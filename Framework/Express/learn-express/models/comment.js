module.exports = (sequelize, DataTypes) => {
    return sequelize.define('comment', {
        comment: {
            type: DataTypes.STRING(100),
            allowNull: true,
        },
        created_at: {
            type: DataTypes.DATE,
            allowNull: false,
            defaultValue: sequelize.literal('now()')
        },
    }, {
        timestamps: false,
    })
}